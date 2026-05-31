////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/asset/ui/UIMetaList.hpp>
#include <yq/tachyon/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UIMetaListWriter : public UIElementWriter {
    public:
        UIMetaListWriter();
        UIMetaListWriter(UIMetaList*);
        UIMetaListWriter(const UIMetaListWriter&);
        ~UIMetaListWriter();
        
        UIMetaList* element();
        
        UIMetaListWriter  drag_type(std::string_view);
    };
}
