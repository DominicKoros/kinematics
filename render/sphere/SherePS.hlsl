struct PS_INPUT
{
    float4 Position : SV_POSITION;
    float3 Normal : NORMAL;
    float2 TexCoord : TEXCOORD0;
};

float4 main(PS_INPUT input) : SV_TARGET
{
    // Simple diffuse lighting
    float3 lightDir = normalize(float3(0.0f, 1.0f, -1.0f));
    float lightIntensity = max(dot(input.Normal, lightDir), 0.0f);
    return float4(lightIntensity, lightIntensity, lightIntensity, 1.0f);
}
