////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/MetaBinder.hpp>
#include <yq/meta/Meta.hpp>
//#include <yq/tachyon/preamble.hpp>
#include <tachyon/gfx/DataFormat.hpp>
#include <tachyon/gfx/IndexType.hpp>
#include <span>

namespace yq::tachyon {
    struct DataFormatData {
        Meta::id_t          type_id     = 0;    //!< Meta type ID
        unsigned int        bindings    = 1;    //!< Number of bindings to be used
        DataFormat          format;             //!< Data format
        IndexType           index;
    };
    
    std::span<const DataFormatData>   data_format_data();

    DataFormat      data_format(const TypeMeta&);
    template <typename T>
    DataFormat      data_format()
    {
        return data_format(meta<T>());
    }
    
    unsigned int    data_binding(const TypeMeta&);
    
    unsigned int    min_binding(size_t);
    
    template <typename T>
    unsigned int    min_binding()
    {
        return min_binding(sizeof(T));
    }
    
    template <typename T>
    unsigned int    data_binding()
    {
        return data_binding(meta<T>());
    }
    
    IndexType       index_type(const TypeMeta&);
    
    template <typename T>
    IndexType       index_type()
    {
        return index_type(meta<T>());
    }
}
