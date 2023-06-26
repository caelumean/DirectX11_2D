#pragma once
#include "yaScene.h"

namespace ya
{
	class WagonBottomScene : public Scene
	{
	public:
		WagonBottomScene();
		~WagonBottomScene();
	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	};
}


