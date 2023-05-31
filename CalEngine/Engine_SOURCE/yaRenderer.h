#pragma once
#include "CalEngine.h"
#include "yaGraphicDevice_Dx11.h"

using namespace ya::math;
namespace ya::renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	extern Vertex Trianglevertexes[];
	extern ID3D11InputLayout* triangleLayout;
	extern ID3D11Buffer* triangleBuffer;
	extern ID3DBlob* errorBlob;
	extern ID3DBlob* triangleVSBlob;
	extern ID3D11VertexShader* triangleVSShader;
	extern ID3DBlob* trianglePSBlob;
	extern ID3D11PixelShader* trianglePSShader;

	extern Vertex Squarevertexes[];
	extern ID3D11InputLayout* squreLayout;
	extern ID3D11Buffer* squreBuffer;
	extern ID3DBlob* errorBlob;
	extern ID3DBlob* squreVSBlob;
	extern ID3D11VertexShader* squreVSShader;
	extern ID3DBlob* squrePSBlob;
	extern ID3D11PixelShader* squrePSShader;


	void Initialize();
}
