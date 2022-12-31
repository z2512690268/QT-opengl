#include "Dice.h"

Dice::Dice()
	: Model()
{
	setVertices({
		//   顶点           纹理	          法线
		// 1
			{{-1,  1,  1,}, {0.50, 0.25}, {0, 0, 1}},	// 左上
			{{-1, -1,  1,}, {0.50, 0.50}, {0, 0, 1}},	// 左下
			{{ 1, -1,  1,}, {0.75, 0.50}, {0, 0, 1}},	// 右下
			{{ 1,  1,  1,}, {0.75, 0.25}, {0, 0, 1}},	// 右上
		// 6							
			{{ 1,  1, -1,}, {0.00, 0.25}, {0, 0, -1}},	// 左上
			{{ 1, -1, -1,}, {0.00, 0.50}, {0, 0, -1}},	// 左下
			{{-1, -1, -1,}, {0.25, 0.50}, {0, 0, -1}},	// 右下
			{{-1,  1, -1,}, {0.25, 0.25}, {0, 0, -1}},	// 右上
		// 2							
			{{ 1,  1,  1,}, {0.75, 0.25}, {1, 0, 0}},	// 左上
			{{ 1, -1,  1,}, {0.75, 0.50}, {1, 0, 0}},	// 左下
			{{ 1, -1, -1,}, {1.00, 0.50}, {1, 0, 0}},	// 右下
			{{ 1,  1, -1,}, {1.00, 0.25}, {1, 0, 0}},	// 右上
		// 5							
			{{-1,  1, -1,}, {0.25, 0.25}, {-1, 0, 0}},	// 左上
			{{-1, -1, -1,}, {0.25, 0.50}, {-1, 0, 0}},	// 左下
			{{-1, -1,  1,}, {0.50, 0.50}, {-1, 0, 0}},	// 右下
			{{-1,  1,  1,}, {0.50, 0.25}, {-1, 0, 0}},	// 右上
		// 3							
			{{-1,  1, -1,}, {0.00, 0.00}, {0, 1, 0}},	// 左上
			{{-1,  1,  1,}, {0.00, 0.25}, {0, 1, 0}},	// 左下
			{{ 1,  1,  1,}, {0.25, 0.25}, {0, 1, 0}},	// 右下
			{{ 1,  1, -1,}, {0.25, 0.00}, {0, 1, 0}},	// 右上
		// 4							
			{{-1, -1,  1,}, {0.00, 0.50}, {0, -1, 0}},	// 左上
			{{-1, -1, -1,}, {0.00, 0.75}, {0, -1, 0}},	// 左下
			{{ 1, -1, -1,}, {0.25, 0.75}, {0, -1, 0}},	// 右下
			{{ 1, -1,  1,}, {0.25, 0.50}, {0, -1, 0}},	// 右上
		});

	auto _texture = new QOpenGLTexture(QImage(":/pic/pic/test.png"));
	_texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
	_texture->setMagnificationFilter(QOpenGLTexture::Linear);
	setTexture(_texture);

	Material material;
	material.ambient = 0;
	material.diffuse = 1;
	material.specular = 0.2;
	material.shininess = 16;
	setMaterial(material, -1);

	auto _program = new QOpenGLShaderProgram();
	_program->addShaderFromSourceCode(QOpenGLShader::Vertex, u8R"(#version 300 es
// // Set default precision to medium
precision mediump int;
precision mediump float;

in vec3 vPos;
in vec2 vTexture;
in vec3 vNormal;

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoords;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
	FragPos = vec3(model * vec4(vPos, 1.0));
	Normal = mat3(transpose(inverse(model))) * vNormal;
	TexCoords = vTexture;

	gl_Position = projection * view * model * vec4(vPos, 1.0);
}
)");
	_program->addShaderFromSourceCode(QOpenGLShader::Fragment, u8R"(#version 300 es
// // Set default precision to medium
precision mediump int;
precision mediump float;

out vec4 FragColor;

struct Material {
    sampler2D texture;
    float ambient;
    float diffuse;
    float specular;
    float shininess;
};

struct Light {
    vec3 position;
    vec3 color;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    // // ambient
    float ambient = material.ambient;

    // // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    float diffuse = material.diffuse * diff;

    // // specular
    float spec = 0.0;
    if (diff > 0.0)
    {
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);
        vec3 halfwayDir = normalize(lightDir + viewDir);
        spec = pow(max(dot(norm, halfwayDir), 0.0), material.shininess);
    }
    float specular = material.specular * spec;

    // // final
    vec3 result = (ambient + diffuse) * texture(material.texture, TexCoords).rgb * light.color 
        + specular * light.color;

    FragColor = vec4(result, 1.0);
}
)");
	setShaderProgram(_program);
	// if (!m_program->isLinked());
	// 	m_program->link();
}

Dice::~Dice()
{
}

void Dice::init()
{
	initializeOpenGLFunctions();
	if (!m_vao.isCreated())
		m_vao.create();
	if (!m_vbo.isCreated())
		m_vbo.create();
	if (!m_program->isLinked())
		m_program->link();

	if (m_vertexCount < m_vertices.count())
	{
		if (m_vertexBuffer)
			delete[] m_vertexBuffer;
		m_vertexBuffer = new float[m_vertices.count() * VertexFloatCount];
		m_vertexCount = m_vertices.count();
		int _offset = 0;
		for (auto &vertex : m_vertices)
		{
			m_vertexBuffer[_offset] = vertex.pos.x(); _offset++;
			m_vertexBuffer[_offset] = vertex.pos.y(); _offset++;
			m_vertexBuffer[_offset] = vertex.pos.z(); _offset++;
			m_vertexBuffer[_offset] = vertex.texture.x(); _offset++;
			m_vertexBuffer[_offset] = vertex.texture.y(); _offset++;
			m_vertexBuffer[_offset] = vertex.normal.x(); _offset++;
			m_vertexBuffer[_offset] = vertex.normal.y(); _offset++;
			m_vertexBuffer[_offset] = vertex.normal.z(); _offset++;
		}
	}

	m_vao.bind();
	m_vbo.bind();
	m_vbo.allocate(m_vertexBuffer, sizeof(float) * m_vertices.count() * VertexFloatCount);

	m_program->bind();
	
	// 绑定顶点坐标信息, 从0 * sizeof(float)字节开始读取3个float, 因为一个顶点有8个float数据, 所以下一个数据需要偏移8 * sizeof(float)个字节
	m_program->setAttributeBuffer("vPos", GL_FLOAT, 0 * sizeof(float), 3, VertexFloatCount * sizeof(float));
	m_program->enableAttributeArray("vPos");
	// 绑定纹理坐标信息, 从3 * sizeof(float)字节开始读取2个float, 因为一个顶点有8个float数据, 所以下一个数据需要偏移8 * sizeof(float)个字节
	m_program->setAttributeBuffer("vTexture", GL_FLOAT, 3 * sizeof(float), 2, VertexFloatCount * sizeof(float));
	m_program->enableAttributeArray("vTexture");
	// 绑定法线坐标信息, 从5 * sizeof(float)字节开始读取3个float, 因为一个顶点有8个float数据, 所以下一个数据需要偏移8 * sizeof(float)个字节
	m_program->setAttributeBuffer("vNormal", GL_FLOAT, 5 * sizeof(float), 3, VertexFloatCount * sizeof(float));
	m_program->enableAttributeArray("vNormal");
	m_program->release();

	m_vbo.release();
	m_vao.release();
}

void Dice::update()
{
}

void Dice::paint()
{
	qDebug() << "paint" << endl;
	qDebug() << "paint" << endl;
	qDebug() << "paint" << endl;
	qDebug() << "paint" << endl;
	qDebug() << "paint" << endl;
	qDebug() << "paint" << endl;
	qDebug() << "paint" << endl;
	qDebug() << "paintEnd" << endl;

	for (auto index : m_textures.keys())
	{
		m_textures[index]->bind(index);
	}
	m_vao.bind();
	m_program->bind();
	// 绑定变换矩阵
	// qDebug() << "####################################################" << endl;
	// qDebug() << "####################################################" << endl;
	// qDebug() << "####################################################" << endl;
	// qDebug() << "####################################################" << endl;
	// qDebug() << "####################################################" << endl;
	m_program->setUniformValue("projection", m_projection);
	m_program->setUniformValue("view", m_camera->view());
	m_program->setUniformValue("viewPos", m_camera->pos());
	m_program->setUniformValue("model", model());
	// 设定灯光位置与颜色
	m_program->setUniformValue("light.position", m_light->pos());
	m_program->setUniformValue("light.color", m_light->color().redF(), m_light->color().greenF(), m_light->color().blueF());
	auto &_material = m_materials.value(0);
	// 设定材质
	m_program->setUniformValue("material.ambient", _material.ambient);
	m_program->setUniformValue("material.diffuse", _material.diffuse);
	m_program->setUniformValue("material.specular", _material.specular);
	m_program->setUniformValue("material.shininess", _material.shininess);
	// 绘制
	for (int i = 0; i < 6; ++i)
	{
		glDrawArrays(GL_TRIANGLE_FAN, i * 4, 4);
	}
	m_program->release();
	m_vao.release();
	for (auto texture : m_textures)
	{
		texture->release();
	}
}
