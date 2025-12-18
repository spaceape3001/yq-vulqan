////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ASize1.hpp>
#include <yq/tachyon/command/size/AddSize1Command.hpp>
#include <yq/tachyon/command/size/AddSizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize1Command.hpp>
#include <yq/tachyon/command/size/MultiplySizeXCommand.hpp>
#include <yq/tachyon/command/size/SetSize1Command.hpp>
#include <yq/tachyon/command/size/SetSizeXCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASize¹::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<ISize¹>();
        w.property(UNSAFE, "size", &ASize¹::m_size).def_value(kDefSize).tag(kTag_Save);
        
        w.slot(UNSAFE, &ASize¹::on_set_size1);
        w.slot(UNSAFE, &ASize¹::on_set_sizeX);

        w.slot(UNSAFE, &ASize¹::on_add_size1);
        w.slot(UNSAFE, &ASize¹::on_add_sizeX);
        
        w.slot(UNSAFE, &ASize¹::on_multiply_size);
        w.slot(UNSAFE, &ASize¹::on_multiply_size1);
        w.slot(UNSAFE, &ASize¹::on_multiply_sizeX);
    }
}
