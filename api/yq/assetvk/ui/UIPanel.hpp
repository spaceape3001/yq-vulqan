////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIWindow.hpp>
#include <yq/trait/numbers.hpp>
#include <memory>

namespace yq::tachyon {
    class UIPanelWriter;
    class UIPanel : public UIWindow {
        YQ_OBJECT_DECLARE(UIPanel, UIWindow)
    public:
        using Writer = UIPanelWriter;
    
        UIPanel(std::string_view title, UIFlags flags={});
        UIPanel(const UIPanel&);
        virtual ~UIPanel();
        UIPanel* clone() const override;
        void    render() override;

        struct Calc;
        struct Context;
        
        using CalcSCPtr = std::shared_ptr<const Calc>;
        
        //static AxBox2F      get_bounds(UIPanel*);
        //static float        get_left(UIPanel*);
        //static float        get_right(UIPanel*);
        //static float        get_top(UIPanel*);
        //static float        get_bottom(UIPanel*);
        static UIWindow*    window(const std::string&);
        static UIWindow*    window(uint64_t);
        static UIPanel*     panel(const std::string&);
        static UIPanel*     panel(uint64_t);
        
        //AxBox2F             bounds() const;

        void    bottom(set_k, const CalcSCPtr&);
        void    left(set_k, const CalcSCPtr&);
        void    height(set_k, const CalcSCPtr&);
        void    height(set_k, maximum_k, const CalcSCPtr&);
        void    height(set_k, minimum_k, const CalcSCPtr&);
        void    right(set_k, const CalcSCPtr&);
        void    top(set_k, const CalcSCPtr&);
        void    width(set_k, const CalcSCPtr&);
        void    width(set_k, maximum_k, const CalcSCPtr&);
        void    width(set_k, minimum_k, const CalcSCPtr&);
        
        static void init_meta();

        // and the calculators.... (See UIPanel.hxx)
        struct Fixed;
        struct ScaledH;
        struct ScaledV;
        struct UIDBottom;
        struct UIDLeft;
        struct UIDRight;
        struct UIDTop;
        struct StyToolBar;

    private:
        friend class UIPanelWriter;

        struct Pointers {
            CalcSCPtr    left;
            CalcSCPtr    right;
            CalcSCPtr    top;
            CalcSCPtr    bottom;
            CalcSCPtr    width;
            CalcSCPtr    widthMax;
            CalcSCPtr    widthMin;
            CalcSCPtr    height;
            CalcSCPtr    heightMin;
            CalcSCPtr    heightMax;
            
            Pointers();
            ~Pointers();
            Pointers(const Pointers&);
        };
        
        Pointers            m_calc;
    };
}
