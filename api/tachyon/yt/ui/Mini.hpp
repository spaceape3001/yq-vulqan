////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Widget.hpp>
#include <yt/typedef/accessor.hpp>
#include <yt/typedef/mini.hpp>

namespace yq::tachyon {

    class TypeInfo;

    /*! \brief Mini information
    */
    class MiniInfo : public WidgetInfo {
    public:
        
        template <typename C>  struct Writer;
        
        MiniInfo(std::string_view, WidgetInfo&, const std::source_location& sl = std::source_location::current());
        
        using WidgetInfo::types;
        const std::vector<const TypeInfo*>& types(data_k) const { return m_dataTypes; }
    
        //static std::span<const MiniInfo*>   all();
        //static const MiniInfo*              view(const TypeInfo&);
        //static const MiniInfo*              edit(const TypeInfo&);
    
    private:
        struct Repo;
        static Repo& repo();
    
        std::vector<const TypeInfo*>   m_dataTypes;
    };

    /*! "Small" focused widgets
    
        These are widgets focused to a small, singular task (ie, display/edit one value).
    */
    class Mini : public Widget {
        YQ_TACHYON_INFO(MiniInfo)
        YQ_TACHYON_DECLARE(Mini, Widget)
    public:
    
        Mini();
        virtual ~Mini();
        static void init_info();
        
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
