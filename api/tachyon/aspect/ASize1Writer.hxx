////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/ASize1.hpp>
#include <tachyon/command/size/AddSize1Command.hpp>
#include <tachyon/command/size/AddSizeXCommand.hpp>
#include <tachyon/command/size/MultiplySizeCommand.hpp>
#include <tachyon/command/size/MultiplySize1Command.hpp>
#include <tachyon/command/size/MultiplySizeXCommand.hpp>
#include <tachyon/command/size/SetSize1Command.hpp>
#include <tachyon/command/size/SetSizeXCommand.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASize¹::init_info(TachyonMeta::Writer<C>&w)
    {
        w.template interface<ISize¹>();
        w.property(UNSAFE, "size", &ASize¹::m_size).tag(kTag_Save);
        
        w.slot(UNSAFE, &ASize¹::on_set_size1);
        w.slot(UNSAFE, &ASize¹::on_set_sizeX);

        w.slot(UNSAFE, &ASize¹::on_add_size1);
        w.slot(UNSAFE, &ASize¹::on_add_sizeX);
        
        w.slot(UNSAFE, &ASize¹::on_multiply_size);
        w.slot(UNSAFE, &ASize¹::on_multiply_size1);
        w.slot(UNSAFE, &ASize¹::on_multiply_sizeX);
    }
}
