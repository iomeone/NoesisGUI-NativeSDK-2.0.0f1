////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef __GUI_PROJECTION_H__
#define __GUI_PROJECTION_H__


#include <Noesis.h>
#include <NsGui/CoreApi.h>
#include <NsGui/Animatable.h>
#include <NsGui/IRenderProxyCreator.h>
#include <NsCore/BaseComponent.h>
#include <NsCore/ReflectionDeclare.h>
#include <NsCore/Ptr.h>
#include <NsCore/TypeMetaData.h>
#include <NsMath/MatrixForward.h>


NS_SFORWARD(Drawing, Size)


namespace Noesis
{
namespace Gui
{

NS_WARNING_PUSH
NS_MSVC_WARNING_DISABLE(4251 4275)

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Provides a base class for projections, which describe how to transform an object
/// in 3D space using perspective transforms.
///
/// http://msdn.microsoft.com/en-us/library/system.windows.media.projection.aspx
////////////////////////////////////////////////////////////////////////////////////////////////////
class NS_GUI_CORE_API Projection: public Animatable, public IRenderProxyCreator
{
public:
    NS_DISABLE_COPY(Projection)

    Projection();
    virtual ~Projection() = 0;

    /// Gets Identity transform object
    /// \prop
    static Projection* GetIdentity();

    /// Indicates if current projection is identity
    virtual NsBool IsIdentity() const = 0;

    /// Gets the transformation matrix defined by a transform object
    /// \param surface Defines the size of the surface where this projection is being applied
    /// \param size Determines the size of the object being projected
    virtual Math::Matrix4f GetProjection(const Drawing::Size& surface,
        const Drawing::Size& size) const = 0;

    NS_IMPLEMENT_INTERFACE_FIXUP

private:
    NS_DECLARE_REFLECTION(Projection, Animatable)
};

NS_WARNING_POP

}
}

#endif