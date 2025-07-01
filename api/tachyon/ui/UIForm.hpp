////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/TypedID.hpp>
#include <tachyon/ui/UIElements.hpp>
#include <tachyon/typedef/tachyon.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class UIFormWriter;
    class TachyonMeta;
    class UIForm;
    class InterfaceMeta;
    
    template <typename C>
    concept SomeUIForm = std::derived_from<C,UIForm>;
    
    class UIFormMeta : public UIElements::MyInfo {    // using this syntax in case UIElements gets a dedicated info object
    public:
        template <typename> class Writer;
        
        UIFormMeta(std::string_view, UIElements::MyInfo&, const std::source_location& sl = std::source_location::current());
    
        bool    has_fields() const;
        
        //  TODO... need a tree of recommendeds... (or similar)
        
    private:
        friend class UIForm;
        struct Repo;
        static Repo& repo();
        
        struct Field;
        class FieldExecutor;
        template <SomeUIForm C> struct BoundFieldExecutor;

        std::vector<Field>                  m_fields;
    };
    
    /*! \brief ImGui Form Panel for anything
    */
    class UIForm : public UIElements {
        YQ_OBJECT_INFO(UIFormMeta)
        YQ_OBJECT_DECLARE(UIForm, UIElements)
    public:
        using Writer = UIFormWriter;

        UIForm(UIFlags flags={});
        UIForm(const UIForm&);
        virtual ~UIForm();
        
        static void init_info();
        
        virtual void    render();
       
    protected:
        virtual UIForm*       clone() const = 0;
    };
}
