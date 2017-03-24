////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef __GUI_PANEL_H__
#define __GUI_PANEL_H__


#include <Noesis.h>
#include <NsGui/UIElementCollection.h>
#include <NsGui/FrameworkElement.h>


NS_CFORWARD(Gui, ItemsControl)
NS_CFORWARD(Gui, ItemContainerGenerator)
NS_CFORWARD(Gui, RectangleGeometry)
NS_SFORWARD(Gui, ItemsChangedEventArgs)
NS_SFORWARD(Gui, GeneratorPosition)


namespace Noesis
{
namespace Gui
{

NS_WARNING_PUSH
NS_MSVC_WARNING_DISABLE(4251 4275)

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Provides a base class for all Panel elements. Use Panel elements to position and arrange 
/// child objects.
///
/// http://msdn.microsoft.com/en-us/library/system.windows.controls.panel.aspx
////////////////////////////////////////////////////////////////////////////////////////////////////
class NS_GUI_CORE_API Panel: public FrameworkElement
{
public:
    NS_DISABLE_COPY(Panel)

    Panel();
    virtual ~Panel() = 0;

    /// Invalidates panel Z-order
    void InvalidateZOrder();

    /// Gets or sets panel background
    //@{
    Brush* GetBackground() const;
    void SetBackground(Brush* brush);
    //@}

    /// Gets or sets a value that indicates that this Panel is a container for user interface (UI) 
    /// items that are generated by an ItemsControl. 
    //@{
    NsBool GetIsItemsHost() const;
    void SetIsItemsHost(NsBool value);
    //@}

    /// Gets a value that represents the order on the z-plane in which an element appears
    static NsInt32 GetZIndex(const DependencyObject* element);
    /// Sets a value that represents the order on the z-plane in which an element appears
    static void SetZIndex(DependencyObject* element, NsInt32 value);

    /// Gets children collection
    /// \prop
    UIElementCollection* GetChildren() const;

public:
    /// Dependency properties
    //@{
    static const DependencyProperty* BackgroundProperty;
    static const DependencyProperty* IsItemsHostProperty;
    static const DependencyProperty* ZIndexProperty; // attached property
    //@}

protected:
    UIElementCollection* GetInternalChildren() const;

    void EnsureGenerator();
    ItemContainerGenerator* GetGenerator() const;

    // Creates children collection
    virtual Ptr<UIElementCollection> CreateChildrenCollection(FrameworkElement* logicalParent);

    // Generates item containers hosted in this panel
    virtual void GenerateChildren();

    // Updates children when items changed
    virtual void OnItemsChangedOverride(Core::BaseComponent* sender,
        const ItemsChangedEventArgs& e);

    virtual void OnConnectToGenerator(ItemsControl* itemsControl);
    virtual void OnDisconnectFromGenerator();

    /// From DependencyObject
    //@{
    void OnInit();
    NsBool OnPropertyChanged(const DependencyPropertyChangedEventArgs& args);
    //@}

    /// From Visual
    //@{
    NsSize GetVisualChildrenCount() const;
    Visual* GetVisualChild(NsSize index) const;
    void OnVisualChildrenChanged(Visual* added, Visual* removed);
    //@}

    /// From UIElement
    //@{
    void OnRender(DrawingContext* context);
    //@}

    /// From FrameworkElement
    //@{
    void CloneOverride(FrameworkElement* clone, FrameworkTemplate* template_) const;
    NsSize GetLogicalChildrenCount() const;
    Core::BaseComponent* GetLogicalChild(NsSize index) const;
    void OnTemplatedParentChanged(FrameworkElement* oldParent, FrameworkElement* newParent);
    //@}

private:
    /// Updates Z-order indirection vector taking into account children elements ZIndex
    void UpdateChildrenZOrder();

    void EnsureChildrenCollection(FrameworkElement* logicalParent);

    void ConnectToGenerator();
    void DisconnectFromGenerator();

    friend class ItemsControl;
    void Refresh();

    void OnItemsChanged(Core::BaseComponent* sender, const ItemsChangedEventArgs& e);

    void OnAddItem(const GeneratorPosition& position, NsInt numItems);
    void OnRemoveItem(const GeneratorPosition& position, NsInt numContainers);
    void OnReplaceItem(const GeneratorPosition& position, NsInt numItems, NsInt numContainers);
    void OnMoveItem(const GeneratorPosition& from, const GeneratorPosition& to,
        NsInt numContainers);
    void OnResetItems();

    static void StaticZIndexChanged(DependencyObject* sender,
        const DependencyPropertyChangedEventArgs& args);

private:
    // Collection of child elements of this panel
    Ptr<UIElementCollection> mInternalChildren;

    // Item container generator when Panel is the items host of an ItemsControl
    Ptr<ItemContainerGenerator> mItemContainerGenerator;

    Ptr<RectangleGeometry> mBackgroundGeometry;

    typedef NsVector<NsSize> ZOrderVector;
    ZOrderVector mZOrder;

    NsBool mValidZOrder;

    NS_DECLARE_REFLECTION(Panel, FrameworkElement)
};

NS_WARNING_POP

}
}

#endif
