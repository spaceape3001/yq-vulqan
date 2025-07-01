////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Widget.hpp>
#include <tachyon/typedef/accessor.hpp>
#include <tachyon/typedef/mini.hpp>

namespace yq::tachyon {

    class TypeMeta;

    /*! \brief Mini information
    */
    class MiniMeta : public WidgetMeta {
    public:
        
        template <typename C>  struct Writer;
        
        MiniMeta(std::string_view, WidgetMeta&, const std::source_location& sl = std::source_location::current());
        
        using WidgetMeta::types;
        const std::vector<const TypeMeta*>& types(data_k) const { return m_dataTypes; }
    
        //static std::span<const MiniMeta*>   all();
        //static const MiniMeta*              view(const TypeMeta&);
        //static const MiniMeta*              edit(const TypeMeta&);
    
    private:
        struct Repo;
        static Repo& repo();
    
        std::vector<const TypeMeta*>   m_dataTypes;
    };

    /*! "Small" focused widgets
    
        These are widgets focused to a small, singular task (ie, display/edit one value).
    */
    class Mini : public Widget {
        YQ_TACHYON_META(MiniMeta)
        YQ_TACHYON_DECLARE(Mini, Widget)
    public:
    
        Mini();
        virtual ~Mini();
        static void init_meta();
        
        /*! \brief Sets the accessor
        
            \note Sub-classes may override so they can see if it's their favorite type of
            accessor, but should call this too.
        */
        virtual void    accessor(set_k, AccessorUPtr&&);
        
    protected:
        
        //! Current accessor
        //! \note May be NULL
        Accessor*       accessor();

        //! Current accessor
        //! \note May be NULL
        const Accessor* accessor() const;
        
    private:
        AccessorUPtr        m_accessor;
        
    };
}
