#pragma once
#include "yaScene.h"

namespace ya
{
	class WagonRightScene : public Scene
	{
	public:
		WagonRightScene();
		~WagonRightScene();
	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	};
}


