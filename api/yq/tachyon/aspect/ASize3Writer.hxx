////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ASize3.hpp>
#include <yq/tachyon/command/size/AddSize3Command.hpp>
#include <yq/tachyon/command/size/AddSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddSizeYCommand.hpp>
#include <yq/tachyon/command/size/AddSizeZCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize3Command.hpp>
#include <yq/tachyon/command/size/MultiplySizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeZCommand.hpp>
#include <yq/tachyon/command/size/SetSize3Command.hpp>
#include <yq/tachyon/command/size/SetSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetSizeYCommand.hpp>
#include <yq/tachyon/command/size/SetSizeZCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASize³::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<ISize³>();
        w.property(UNSAFE, "size", &ASize³::m_size).def_value(kDefSize).tag({kTag_Save, kTag_Log});

        w.slot(UNSAFE, &ASize³::on_set_size3);
        w.slot(UNSAFE, &ASize³::on_set_sizeX);
        w.slot(UNSAFE, &ASize³::on_set_sizeY);
        w.slot(UNSAFE, &ASize³::on_set_sizeZ);

        w.slot(UNSAFE, &ASize³::on_add_size3);
        w.slot(UNSAFE, &ASize³::on_add_sizeX);
        w.slot(UNSAFE, &ASize³::on_add_sizeY);
        w.slot(UNSAFE, &ASize³::on_add_sizeZ);
        
        w.slot(UNSAFE, &ASize³::on_multiply_size);
        w.slot(UNSAFE, &ASize³::on_multiply_size3);
        w.slot(UNSAFE, &ASize³::on_multiply_sizeX);
        w.slot(UNSAFE, &ASize³::on_multiply_sizeY);
        w.slot(UNSAFE, &ASize³::on_multiply_sizeZ);
    }
}
