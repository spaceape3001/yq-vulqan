////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/widget/FormWidget.hpp>
#include <tachyon/api/Tachyon.hxx>
#include <tachyon/mini/TextLabel.hpp>
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/WidgetInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::FormWidget)

namespace yq::tachyon {
    void FormWidget::init_info()
    {
        auto w = writer<FormWidget>();
        w.description("Form Widget");
    }
    
    FormWidget::FormWidget()
    {
    }
    
    FormWidget::~FormWidget()
    {
    }

    bool FormWidget::add_row(Mini* m, Widget* w)
    {
        if(m && w){
            m_rows.push_back({m,w});
            return true;
        } else {
            return false;
        }
    }

    bool FormWidget::add_row(std::string_view k, Widget* w)
    {
        if(!w)
            return false;
        return add_row( create_child<TextLabel>(k), w);
    }
    
    bool FormWidget::add_row(AccessorUPtr&&acc, Widget*w)
    {
        if(!w)
            return false;
        if(!acc)
            return false;
        return add_row( create_child<TextLabel>(std::move(acc)), w);
    }

    FormWidget::Adder   FormWidget::add_row(std::string_view k)
    {
        return Adder( this, create_child<TextLabel>(k));
    }
    
    FormWidget::Adder   FormWidget::add_row(AccessorUPtr&& acc)
    {
        return Adder( this, create_child<TextLabel>(std::move(acc)));
    }

    FormWidget::Adder   FormWidget::add_row(SVFN&&fn)
    {
        return Adder( this, create_child<TextLabel>(std::move(fn)));
    }

    bool FormWidget::add_row(std::string_view k, std::string_view v)
    {
        return add_row( 
            create_child<TextLabel>(k),
            create_child<TextLabel>(v)
        );
    }
    
    bool FormWidget::add_row(std::string_view k, AccessorUPtr&& v)
    {
        if(!v)
            return false;
        return add_row( 
            create_child<TextLabel>(k),
            create_child<TextLabel>(std::move(v))
        );
    }

    bool FormWidget::add_row(std::string_view k, SVFN&&v)
    {
        if(!v)
            return false;
        return add_row( 
            create_child<TextLabel>(k),
            create_child<TextLabel>(std::move(v))
        );
    }
    
    bool FormWidget::add_row(AccessorUPtr&& k, AccessorUPtr&& v)
    {
        if(!k)
            return false;
        if(!v)
            return false;
        return add_row( 
            create_child<TextLabel>(std::move(k)),
            create_child<TextLabel>(std::move(v))
        );
    }
    
    void FormWidget::imgui(ViContext&ctx) 
    {
        if(ImGui::BeginTable(imgui_id(), 2)){
            for(const Row& r : m_rows){
                ImGui::TableNextRow();
                if(ImGui::TableNextColumn()){
                    r.label->imgui(ctx);
                }
                if(ImGui::TableNextColumn()){
                    r.widget->imgui(ctx);
                }
            }
            
            ImGui::EndTable();
        }
    }
    

    ////////////////////////////////////////////////////////////////////////////
    
    FormWidget::Adder::Adder(FormWidget* f, Mini*l) : m_form(f), m_label(l), m_widget(nullptr)
    {
    }
    
    FormWidget::Adder::Adder(Adder&&mv) : m_form(mv.m_form), m_label(mv.m_label), m_widget(mv.m_widget)
    {
        mv.m_form   = nullptr;
        mv.m_label  = nullptr;
        mv.m_widget = nullptr;
    }
    
    FormWidget::Adder& FormWidget::Adder::operator=(Adder&&mv)
    {
        if(this != &mv){
            m_form      = mv.m_form;
            m_label     = mv.m_label;
            m_widget    = mv.m_widget;

            mv.m_form   = nullptr;
            mv.m_label  = nullptr;
            mv.m_widget = nullptr;
        }
        return *this;
    }
    
    FormWidget::Adder::~Adder()
    {
        if(m_form && m_label && m_widget){
            m_form -> m_rows.push_back({m_label, m_widget});
        }

        m_form   = nullptr;
        m_label  = nullptr;
        m_widget = nullptr;
    }
    
    bool    FormWidget::Adder::widget(Widget*w)
    {
        if(m_form && m_label && w){
            m_widget    = w;
            return true;
        }
        return false;
    }
}
