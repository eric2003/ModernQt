#version 330 core
out vec4 FragColor;
in vec3 ourColor;
in vec2 TexCord;
uniform sampler2D textureWall;
uniform sampler2D texturePrint;
uniform sampler2D textureSmall;
void main()
{
    //FragColor = mix( texture(textureWall, TexCord),
    //                 texture(texturePrint, TexCord), 0.5 );
    FragColor = texture(textureSmall, TexCord);
}
