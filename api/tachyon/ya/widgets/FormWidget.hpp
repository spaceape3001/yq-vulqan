////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Mini.hpp>
#include <yt/ui/Widget.hpp>
#include <ya/typedef/accessors.hpp>
#include <functional>

namespace yq::tachyon {

    class FormWidget : public Widget {
        YQ_TACHYON_DECLARE(FormWidget, Widget)
    public:
    
        using SVFN  = std::function<std::string_view()>;
        
        FormWidget();
        ~FormWidget();
        
        void imgui(ViContext&) override;
        
        static void init_info();
        
        class Adder;
        
        Adder   add_row(std::string_view);
        Adder   add_row(AccessorUPtr&&);
        Adder   add_row(SVFN&&);
        
        template <SomeMini, typename... Args>
        Adder   add_row(Args...);

        bool    add_row(std::string_view, Widget*);
        bool    add_row(AccessorUPtr&&, Widget*);
        bool    add_row(Mini*, Widget*);
        
        bool    add_row(std::string_view, std::string_view);
        bool    add_row(std::string_view, AccessorUPtr&&);
        bool    add_row(std::string_view, SVFN&&);
        bool    add_row(AccessorUPtr&&, AccessorUPtr&&);

    private:
        struct Row {
            Mini*   label   = nullptr;
            Widget* widget  = nullptr;
        };
        
        std::vector<Row>    m_rows;
    };
    
    class FormWidget::Adder {
    public:
        
        Adder(Adder&&);
        Adder& operator=(Adder&&);
        
        ~Adder();
        
        bool    widget(Widget*);
        
        template <SomeWidget, typename...Args>
        bool    widget(Args...);
        
    private:
        friend class FormWidget;
        Adder(FormWidget*, Mini*);
    
        FormWidget* m_form      = nullptr;
        Mini*       m_label     = nullptr;
        Widget*     m_widget    = nullptr;
        
        Adder(const Adder&) = delete;
        Adder& operator=(const Adder&) = delete;
    };

    template <SomeMini M, typename... Args>
    FormWidget::Adder   FormWidget::add_row(Args...args)
    {
        M*  label   = create<M>(CHILD, args...);
        if(!label){
            return Adder(nullptr, nullptr);
        }
        return Adder(this, label);
    }

    template <SomeWidget W, typename...Args>
    bool   FormWidget::Adder::widget(Args... args)
    {
        if(!m_label || !m_form)
            return false;
        
        m_widget    = create<W>(CHILD, args...);
        return true;
    }
}

