////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/ASize4.hpp>
#include <tachyon/command/size/AddSize4Command.hpp>
#include <tachyon/command/size/AddSizeWCommand.hpp>
#include <tachyon/command/size/AddSizeXCommand.hpp>
#include <tachyon/command/size/AddSizeYCommand.hpp>
#include <tachyon/command/size/AddSizeZCommand.hpp>
#include <tachyon/command/size/MultiplySizeCommand.hpp>
#include <tachyon/command/size/MultiplySize4Command.hpp>
#include <tachyon/command/size/MultiplySizeWCommand.hpp>
#include <tachyon/command/size/MultiplySizeXCommand.hpp>
#include <tachyon/command/size/MultiplySizeYCommand.hpp>
#include <tachyon/command/size/MultiplySizeZCommand.hpp>
#include <tachyon/command/size/SetSize4Command.hpp>
#include <tachyon/command/size/SetSizeWCommand.hpp>
#include <tachyon/command/size/SetSizeXCommand.hpp>
#include <tachyon/command/size/SetSizeYCommand.hpp>
#include <tachyon/command/size/SetSizeZCommand.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASize⁴::init_info(TachyonMeta::Writer<C>&w)
    {
        w.template interface<ISize⁴>();
        w.property(UNSAFE, "size", &ASize⁴::m_size).tag(kTag_Save);

        w.slot(UNSAFE, &ASize⁴::on_set_size4);
        w.slot(UNSAFE, &ASize⁴::on_set_sizeW);
        w.slot(UNSAFE, &ASize⁴::on_set_sizeX);
        w.slot(UNSAFE, &ASize⁴::on_set_sizeY);
        w.slot(UNSAFE, &ASize⁴::on_set_sizeZ);

        w.slot(UNSAFE, &ASize⁴::on_add_size4);
        w.slot(UNSAFE, &ASize⁴::on_add_sizeW);
        w.slot(UNSAFE, &ASize⁴::on_add_sizeX);
        w.slot(UNSAFE, &ASize⁴::on_add_sizeY);
        w.slot(UNSAFE, &ASize⁴::on_add_sizeZ);
        
        w.slot(UNSAFE, &ASize⁴::on_multiply_size);
        w.slot(UNSAFE, &ASize⁴::on_multiply_size4);
        w.slot(UNSAFE, &ASize⁴::on_multiply_sizeX);
        w.slot(UNSAFE, &ASize⁴::on_multiply_sizeW);
        w.slot(UNSAFE, &ASize⁴::on_multiply_sizeY);
        w.slot(UNSAFE, &ASize⁴::on_multiply_sizeZ);
    }
}
