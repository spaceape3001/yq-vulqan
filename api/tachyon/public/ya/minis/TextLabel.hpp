////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Mini.hpp>
#include <ya/accessors/StringValue.hpp>

namespace yq::tachyon {
    class TextLabel : public Mini {
        YQ_TACHYON_DECLARE(TextLabel, Mini)
    public:
        
        using FN    = std::function<std::string_view()>;
    
        TextLabel();
        
        template <typename T>
        TextLabel(T v)
        {
            accessor(SET, std::make_unique<StringValue>(v));
        }

        TextLabel(AccessorUPtr&&);
        TextLabel(FN&&);
        
        using Mini::accessor;
        virtual void    accessor(set_k, AccessorUPtr&&) override;
        virtual void    imgui(ViContext&) override;

    private:
        ~TextLabel();

        StringAccessor* m_accessor  = nullptr;
    };
}

