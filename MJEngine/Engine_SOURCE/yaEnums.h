#pragma once


namespace ya::enums
{
	enum class eComponentType
	{
		None,
		Transform,
		Mesh,
		Particle,
		MeshRenderer,
		Script,
		Camera,
		End,
	};
	enum class eSceneType
	{
		Title,
		Play,
		End,
	};
	enum class eLayerType
	{
		BG1,
		BG2,
		BG3,
		Player,
		Monster,
		Boss,
		UI,
		Text,
		End,
	};

	enum class eResourceType
	{
		Texture,
		Shader,
		Material,
		Mesh,
		End,
	};
}