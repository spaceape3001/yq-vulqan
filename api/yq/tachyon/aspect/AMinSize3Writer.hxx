////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AMinSize3.hpp>
#include <yq/tachyon/command/size/AddMinSize3Command.hpp>
#include <yq/tachyon/command/size/AddMinSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeYCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeZCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize3Command.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeZCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize3Command.hpp>
#include <yq/tachyon/command/size/SetMinSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeYCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeZCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMinSize³::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IMinSize³>();
        w.property(UNSAFE, "min_size", &AMinSize³::m_min_size).tag(kTag_Save);

        w.slot(UNSAFE, &AMinSize³::on_set_min_size3);
        w.slot(UNSAFE, &AMinSize³::on_set_min_sizeX);
        w.slot(UNSAFE, &AMinSize³::on_set_min_sizeY);
        w.slot(UNSAFE, &AMinSize³::on_set_min_sizeZ);

        w.slot(UNSAFE, &AMinSize³::on_add_min_size3);
        w.slot(UNSAFE, &AMinSize³::on_add_min_sizeX);
        w.slot(UNSAFE, &AMinSize³::on_add_min_sizeY);
        w.slot(UNSAFE, &AMinSize³::on_add_min_sizeZ);
        
        w.slot(UNSAFE, &AMinSize³::on_multiply_min_size);
        w.slot(UNSAFE, &AMinSize³::on_multiply_min_size3);
        w.slot(UNSAFE, &AMinSize³::on_multiply_min_sizeX);
        w.slot(UNSAFE, &AMinSize³::on_multiply_min_sizeY);
        w.slot(UNSAFE, &AMinSize³::on_multiply_min_sizeZ);
    }
}
