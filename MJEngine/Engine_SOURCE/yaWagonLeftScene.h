#pragma once
#include "yaScene.h"

namespace ya
{
	class WagonLeftScene : public Scene
	{
	public:
		WagonLeftScene();
		~WagonLeftScene();

	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	};

}

