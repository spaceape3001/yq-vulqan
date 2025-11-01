////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AMaxSize1.hpp>
#include <yq/tachyon/command/size/AddMaxSize1Command.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize1Command.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize1Command.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMaxSize¹::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IMaxSize¹>();
        w.property(UNSAFE, "max_size", &AMaxSize¹::m_max_size).tag(kTag_Save);
        
        w.slot(UNSAFE, &AMaxSize¹::on_set_max_size1);
        w.slot(UNSAFE, &AMaxSize¹::on_set_max_sizeX);

        w.slot(UNSAFE, &AMaxSize¹::on_add_max_size1);
        w.slot(UNSAFE, &AMaxSize¹::on_add_max_sizeX);
        
        w.slot(UNSAFE, &AMaxSize¹::on_multiply_max_size);
        w.slot(UNSAFE, &AMaxSize¹::on_multiply_max_size1);
        w.slot(UNSAFE, &AMaxSize¹::on_multiply_max_sizeX);
    }
}
