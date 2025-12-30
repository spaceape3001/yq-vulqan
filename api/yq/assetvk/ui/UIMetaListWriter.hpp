////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElementWriter.hpp>
#include <yq/assetvk/ui/UIMetaList.hpp>

namespace yq::tachyon {
    class UIMetaList;
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
