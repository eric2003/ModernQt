#version 330 core
out vec4 FragColor;
in vec3 ourColor;
in vec2 TexCord;
uniform sampler2D textureWall;
uniform sampler2D texturePrint;
void main()
{
    //FragColor = texture(textureWall, TexCord);
    FragColor = mix( texture(textureWall, TexCord), texture(texturePrint, TexCord), 0.5 ) ;
}
