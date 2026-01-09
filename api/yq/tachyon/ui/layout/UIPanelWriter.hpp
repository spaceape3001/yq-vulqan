////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/layout/UIPanel.hpp>
#include <yq/tachyon/ui/UIWindowWriter.hpp>

namespace yq::tachyon {
    class UIPanelWriter : public UIWindowWriter {
    public:
        UIPanelWriter();
        UIPanelWriter(UIPanel*);
        UIPanelWriter(const UIPanelWriter&);
        ~UIPanelWriter();
        
        UIPanel*  element();
  

        // T/B/R/L or N/S/E/W & W/H (note, W/H take precedence)
        
        // we're using "pivot" in lieu of "fraction" due to naming collision

        UIPanelWriter&  bottom(const UIPanel::CalcSCPtr&);
        UIPanelWriter&  bottom(float);
        UIPanelWriter&  bottom(pivot_k, float);
        UIPanelWriter&  bottom(std::string_view, bottom_k);
        UIPanelWriter&  bottom(std::string_view, top_k);

        UIPanelWriter&  height(const UIPanel::CalcSCPtr&);
        UIPanelWriter&  height(float);
        UIPanelWriter&  height(pivot_k, float);
        UIPanelWriter&  height(toolbar_k);

        UIPanelWriter&  height(maximum_k, const UIPanel::CalcSCPtr&);
        UIPanelWriter&  height(maximum_k, float);
        UIPanelWriter&  height(maximum_k, pivot_k, float);

        UIPanelWriter&  height(minimum_k, const UIPanel::CalcSCPtr&);
        UIPanelWriter&  height(minimum_k, float);
        UIPanelWriter&  height(minimum_k, pivot_k, float);

        UIPanelWriter&  height(start_k, const UIPanel::CalcSCPtr&);
        UIPanelWriter&  height(start_k, float);
        UIPanelWriter&  height(start_k, pivot_k, float);

        UIPanelWriter&  left(const UIPanel::CalcSCPtr&);
        UIPanelWriter&  left(float);
        UIPanelWriter&  left(pivot_k, float);
        UIPanelWriter&  left(std::string_view, left_k);
        UIPanelWriter&  left(std::string_view, right_k);

        UIPanelWriter&  right(const UIPanel::CalcSCPtr&);
        UIPanelWriter&  right(float);
        UIPanelWriter&  right(pivot_k, float);
        UIPanelWriter&  right(std::string_view, left_k);
        UIPanelWriter&  right(std::string_view, right_k);
        
        UIPanelWriter&  top(const UIPanel::CalcSCPtr&);
        UIPanelWriter&  top(float);
        UIPanelWriter&  top(pivot_k, float);
        UIPanelWriter&  top(std::string_view, bottom_k);
        UIPanelWriter&  top(std::string_view, top_k);

        UIPanelWriter&  width(const UIPanel::CalcSCPtr&);
        UIPanelWriter&  width(float);
        UIPanelWriter&  width(pivot_k, float);
        UIPanelWriter&  width(toolbar_k);

        UIPanelWriter&  width(maximum_k, const UIPanel::CalcSCPtr&);
        UIPanelWriter&  width(maximum_k, float);
        UIPanelWriter&  width(maximum_k, pivot_k, float);

        UIPanelWriter&  width(minimum_k, const UIPanel::CalcSCPtr&);
        UIPanelWriter&  width(minimum_k, float);
        UIPanelWriter&  width(minimum_k, pivot_k, float);

        UIPanelWriter&  width(start_k, const UIPanel::CalcSCPtr&);
        UIPanelWriter&  width(start_k, float);
        UIPanelWriter&  width(start_k, pivot_k, float);
    };
}
