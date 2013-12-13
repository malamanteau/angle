﻿#pragma once

#include "DirectXBase.h"
#include <DirectXMath.h>

// This class renders a simple spinning cube.
ref class CubeRenderer sealed : public DirectXBase
{
public:
	CubeRenderer();

	// Direct3DBase methods.
	virtual void CreateDeviceResources() override;
	virtual void CreateWindowSizeDependentResources() override;
	void Update(float timeTotal, float timeDelta);
	virtual void OnOrientationChanged(Windows::Graphics::Display::DisplayOrientations orientation) override;
	virtual void OnRender() override;
    virtual void CreateAngleResources() override;

private:
    void UpdatePerspectiveMatrix();

    bool m_loadingComplete;
    GLuint m_colorProgram;
    GLint a_positionColor;
    GLint a_colorColor;
    GLint u_mvpColor;
    DirectX::XMMATRIX m_projectionMatrix;
    DirectX::XMMATRIX m_viewMatrix;
    DirectX::XMMATRIX m_modelMatrix;
};