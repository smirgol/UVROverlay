#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
#include <windows.h>
#include <openvr.h>
//#include <windows.h>
class Overlay
{
public:

	virtual ~Overlay() {}

	virtual bool ShowOverlay() = 0;
	virtual void HideOverlay() = 0;
	virtual void handleEvent(const vr::VREvent_t& event) = 0;
	virtual void updateTexture() = 0;
	virtual void setOverlayMatrix(const vr::HmdMatrix34_t& relativePosition) = 0;
	virtual vr::HmdMatrix34_t getOverlayMatrix() const = 0;
	virtual boost::uuids::uuid getOverlayUuid() const = 0;
	virtual void setRotate(const int axis, const int value)=0;
	virtual void setTrans(const int axis, const int value)=0;

	virtual vr::VROverlayHandle_t getOverlayHandle() const = 0;

	virtual void setScale(const int scale) = 0;
	virtual int getScale() const =0;

	virtual void setTracking(uint32_t device)=0;
	virtual uint32_t getTracking() const = 0 ;


	virtual void asyncUpdate() = 0;

	virtual int getRotate(const int axis) const = 0 ;
	virtual int getTrans(const int axis) const = 0 ;

	virtual std::wstring getName() const =0;
	virtual void setName(const std::wstring& name)=0 ;

	virtual unsigned int getWidth() const = 0;
	virtual unsigned int getHeight() const = 0;

	virtual bool isVisible() const = 0;
};

//overlay helper functions

vr::HmdMatrix44_t multMatrix(vr::HmdMatrix44_t m1, vr::HmdMatrix44_t m2)
{
	vr::HmdMatrix44_t result;
	memset(&result, 0, sizeof(result));

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				result.m[i][j] += m1.m[i][k] * m2.m[k][j];

	return result;
}

