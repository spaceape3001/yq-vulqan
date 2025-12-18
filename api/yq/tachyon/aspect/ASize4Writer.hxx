////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ASize4.hpp>
#include <yq/tachyon/command/size/AddSize4Command.hpp>
#include <yq/tachyon/command/size/AddSizeWCommand.hpp>
#include <yq/tachyon/command/size/AddSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddSizeYCommand.hpp>
#include <yq/tachyon/command/size/AddSizeZCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize4Command.hpp>
#include <yq/tachyon/command/size/MultiplySizeWCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeZCommand.hpp>
#include <yq/tachyon/command/size/SetSize4Command.hpp>
#include <yq/tachyon/command/size/SetSizeWCommand.hpp>
#include <yq/tachyon/command/size/SetSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetSizeYCommand.hpp>
#include <yq/tachyon/command/size/SetSizeZCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASize⁴::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<ISize⁴>();
        w.property(UNSAFE, "size", &ASize⁴::m_size).def_value(kDefSize).tag(kTag_Save);

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
