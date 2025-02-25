////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/ASize3.hpp>
#include <ya/commands/size/AddSize3.hpp>
#include <ya/commands/size/AddSizeX.hpp>
#include <ya/commands/size/AddSizeY.hpp>
#include <ya/commands/size/AddSizeZ.hpp>
#include <ya/commands/size/MultiplySize.hpp>
#include <ya/commands/size/MultiplySize3.hpp>
#include <ya/commands/size/MultiplySizeX.hpp>
#include <ya/commands/size/MultiplySizeY.hpp>
#include <ya/commands/size/MultiplySizeZ.hpp>
#include <ya/commands/size/SetSize3.hpp>
#include <ya/commands/size/SetSizeX.hpp>
#include <ya/commands/size/SetSizeY.hpp>
#include <ya/commands/size/SetSizeZ.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASize³::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<ISize³>();
        w.property(UNSAFE, "size", &ASize³::m_size).tag(kTag_Save);

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
