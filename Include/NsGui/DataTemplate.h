////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef __GUI_DATATEMPLATE_H__
#define __GUI_DATATEMPLATE_H__


#include <Noesis.h>
#include <NsGui/CoreApi.h>
#include <NsGui/FrameworkTemplate.h>


NS_CFORWARD(Gui, ResourceKeyType)


namespace Noesis
{
namespace Gui
{

NS_WARNING_PUSH
NS_MSVC_WARNING_DISABLE(4251 4275)

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Describes the visual structure of a data object.
///
/// http://msdn.microsoft.com/en-us/library/system.windows.datatemplate.aspx
////////////////////////////////////////////////////////////////////////////////////////////////////
class NS_GUI_CORE_API DataTemplate: public FrameworkTemplate
{
public:
    DataTemplate();
    ~DataTemplate();

    /// Gets or sets the type for which this DataTemplate is intended
    //@{
    ResourceKeyType* GetDataType() const;
    void SetDataType(ResourceKeyType* dataType);
    //@}
    
    /// Gets a collection of triggers that apply property values or perform actions based on one or 
    /// more conditions.
    TriggerCollection* GetTriggers() const;

protected:
    /// From FrameworkTemplate
    //@{
    NsBool IsValidTemplatedParent(FrameworkElement* templatedParent,
        BaseComponent* dataContext) const;
    TriggerCollection* GetAvailableTriggers() const final;
    //@}

private:
    void EnsureTriggers() const;

private:
    Ptr<ResourceKeyType> mDataType;
    mutable Ptr<TriggerCollection> mTriggers;

    NS_DECLARE_REFLECTION(DataTemplate, FrameworkTemplate)
};

NS_WARNING_POP

}
}

#endif