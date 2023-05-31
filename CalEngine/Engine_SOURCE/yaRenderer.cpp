#include "yaRenderer.h"



namespace ya::renderer
{
	//Vertex Trianglevertexes[3] = {};
	Vertex Squarevertexes[36] = {};
	
	// Input Layout (정점 정보)
	ID3D11InputLayout* triangleLayout = nullptr;
	ID3D11InputLayout* squreLayout = nullptr;

	// Vertex Buffer
	ID3D11Buffer* triangleBuffer = nullptr;
	ID3D11Buffer* squreBuffer = nullptr;

	// error blob
	ID3DBlob* errorBlob = nullptr;

	// Vertex Shader code -> Binary Code
	ID3DBlob* triangleVSBlob = nullptr;
	ID3DBlob* squreVSBlob = nullptr;
	// Vertex Shader
	ID3D11VertexShader* triangleVSShader = nullptr;
	ID3D11VertexShader* squreVSShader = nullptr;

	// Pixel Shader code -> Binary Code
	ID3DBlob* trianglePSBlob = nullptr;
	ID3DBlob* squrePSBlob = nullptr;
	// Vertex Shader
	ID3D11PixelShader* trianglePSShader = nullptr;
	ID3D11PixelShader* squrePSShader = nullptr;

	void SetupState()
	{


		

	}

	void LoadBuffer()
	{
		/*D3D11_BUFFER_DESC triangleDesc = {};
		triangleDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		triangleDesc.ByteWidth = sizeof(Vertex) * 4;
		triangleDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;
		triangleDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		D3D11_SUBRESOURCE_DATA triangleData = {};
		triangleData.pSysMem = Trianglevertexes;
		ya::graphics::GetDevice()->CreateBuffer(&triangleBuffer, &triangleDesc, &triangleData);*/

		// 사각형
		D3D11_BUFFER_DESC squreDesc = {};
		squreDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		squreDesc.ByteWidth = sizeof(Vertex) * 36;
		squreDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;
		squreDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		D3D11_SUBRESOURCE_DATA squreData = {};
		squreData.pSysMem = Squarevertexes;
		ya::graphics::GetDevice()->CreateBuffer(&squreBuffer, &squreDesc, &squreData);

	}	

	void LoadShader()
	{
		ya::graphics::GetDevice()->CreateShader();
	}

	void Initialize()
	{
		// 삼각형
		//Trianglevertexes[0].pos = Vector3(0.25f, 0.25f, 0.0f);
		//Trianglevertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		//Trianglevertexes[1].pos = Vector3(0.35f, 0.0f, 0.0f);
		//Trianglevertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		//Trianglevertexes[2].pos = Vector3(0.15f, 0.0f, 0.0f);
		//Trianglevertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		// 사각형
		Squarevertexes[0].pos = Vector3(-0.45f, 0.25f, 0.0f);
		Squarevertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		Squarevertexes[1].pos = Vector3(-0.25f, 0.25f, 0.0f);
		Squarevertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		Squarevertexes[2].pos = Vector3(-0.45f, 0.0f, 0.0f);
		Squarevertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		Squarevertexes[3].pos = Vector3(-0.45f, 0.0f, 0.0f);
		Squarevertexes[3].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f); 
						
		Squarevertexes[4].pos = Vector3(-0.25f, 0.25f, 0.0f);
		Squarevertexes[4].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		Squarevertexes[5].pos = Vector3(-0.25f, 0.0f, 0.0f);
		Squarevertexes[5].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		// 마름모
		Squarevertexes[6].pos = Vector3(-0.15f, 0.25f, 0.0f);
		Squarevertexes[6].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		Squarevertexes[7].pos = Vector3(0.0f, 0.35f, 0.0f);
		Squarevertexes[7].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		Squarevertexes[8].pos = Vector3(0.15f, 0.25f, 0.0f);
		Squarevertexes[8].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		Squarevertexes[9].pos = Vector3(-0.15f, 0.25f, 0.0f);
		Squarevertexes[9].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		Squarevertexes[10].pos = Vector3(0.15f, 0.25f, 0.0f);
		Squarevertexes[10].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		Squarevertexes[11].pos = Vector3(0.0f, 0.15f, 0.0f);
		Squarevertexes[11].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		
		//사다리꼴
		// 1
		Squarevertexes[12].pos = Vector3(0.2f, 0.0f, 0.0f);
		Squarevertexes[12].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		Squarevertexes[13].pos = Vector3(0.3f, 0.0f, 0.0f);
		Squarevertexes[13].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		Squarevertexes[14].pos = Vector3(0.3f, -0.2f, 0.0f);
		Squarevertexes[14].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		// 2
		Squarevertexes[15].pos = Vector3(0.3f, 0.0f, 0.0f);
		Squarevertexes[15].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		Squarevertexes[16].pos = Vector3(0.4f, 0.0f, 0.0f);
		Squarevertexes[16].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		Squarevertexes[17].pos = Vector3(0.3f, -0.2f, 0.0f);
		Squarevertexes[17].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		// 3
		Squarevertexes[18].pos = Vector3(0.3f, -0.2f, 0.0f);
		Squarevertexes[18].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		Squarevertexes[19].pos = Vector3(0.4f, 0.0f, 0.0f);
		Squarevertexes[19].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		Squarevertexes[20].pos = Vector3(0.4f, -0.2f, 0.0f);
		Squarevertexes[20].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		//4
		Squarevertexes[21].pos = Vector3(0.5f, -0.2f, 0.0f);
		Squarevertexes[21].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		Squarevertexes[22].pos = Vector3(0.4f, -0.2f, 0.0f);
		Squarevertexes[22].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		Squarevertexes[23].pos = Vector3(0.4f, 0.0f, 0.0f);
		Squarevertexes[23].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);




		

		
		//Squarevertexes[0].pos = Vector3()

		SetupState();
		LoadBuffer();
		LoadShader();
	}
}



