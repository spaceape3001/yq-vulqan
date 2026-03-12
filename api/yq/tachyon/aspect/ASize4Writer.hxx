////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ASize4.hpp>
#include <yq/tachyon/command/size/AddSize4DCommand.hpp>
#include <yq/tachyon/command/size/AddSizeWDCommand.hpp>
#include <yq/tachyon/command/size/AddSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddSizeYDCommand.hpp>
#include <yq/tachyon/command/size/AddSizeZDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize4DCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeWDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeZDCommand.hpp>
#include <yq/tachyon/command/size/SetSize4DCommand.hpp>
#include <yq/tachyon/command/size/SetSizeWDCommand.hpp>
#include <yq/tachyon/command/size/SetSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetSizeZDCommand.hpp>
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
