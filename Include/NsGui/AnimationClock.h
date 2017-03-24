////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef __GUI_ANIMATIONCLOCK_H__
#define __GUI_ANIMATIONCLOCK_H__


#include <Noesis.h>
#include <NsGui/Clock.h>
#include <NsGui/HandoffBehavior.h>


namespace Noesis
{
namespace Gui
{

// Forward declarations
//@{
class AnimationTimeline;
class DependencyObject;
class DependencyProperty;
NS_INTERFACE ITimeManager;
//@}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Maintains the run-time state of an AnimationTimeline and processes its output values.
///
/// http://msdn.microsoft.com/en-us/library/system.windows.media.animation.animationclock.aspx
////////////////////////////////////////////////////////////////////////////////////////////////////
class NS_GUI_ANIMATION_API AnimationClock: public Clock
{
public:
    AnimationClock(AnimationTimeline* animation, NsBool controllable);
    
    void Start(DependencyObject* object, const DependencyProperty* dp, ITimeManager* timeManager, 
        HandoffBehavior handoff = HandoffBehavior_SnapshotAndReplace);
        
private:
    // From Clock
    //@{
    void Recycle(TimeManager* owner);
    //@}
    
    NS_DECLARE_REFLECTION(AnimationClock, Clock)
};

}
}


#endif
