////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef __GUI_STOPSTORYBOARD_H__
#define __GUI_STOPSTORYBOARD_H__


#include <Noesis.h>
#include <NsGui/AnimationApi.h>
#include <NsGui/ControllableStoryboardAction.h>
#include <NsCore/ReflectionDeclare.h>
#include <NsCore/String.h>


namespace Noesis
{
namespace Gui
{

////////////////////////////////////////////////////////////////////////////////////////////////////
/// A trigger action that stops a Storyboard.
///
/// http://msdn.microsoft.com/en-us/library/system.windows.media.animation.stopstoryboard.aspx
////////////////////////////////////////////////////////////////////////////////////////////////////
class NS_GUI_ANIMATION_API StopStoryboard: public ControllableStoryboardAction
{
protected:
    void Invoke(FrameworkElement* target, Storyboard* storyboard);

    NS_DECLARE_REFLECTION(StopStoryboard, ControllableStoryboardAction)
};

}
}


#endif
