#version 330 core
out vec4 FragColor;
in vec3 ourColor;
in vec2 TexCord;
uniform sampler2D texture0;
void main()
{
    //FragColor = vec4(ourColor, 1.0f);
    FragColor = texture(texture0, TexCord);
}
