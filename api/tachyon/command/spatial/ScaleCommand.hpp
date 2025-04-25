////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/SpatialCommand.hpp>

namespace yq::tachyon {
    class ScaleCommand : public SpatialCommand {
        YQ_OBJECT_DECLARE(ScaleCommand, SpatialCommand)
    public:
        ScaleCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        ScaleCommand(const ScaleCommand&, const Header&);
        virtual ~ScaleCommand();
        
    private:

        ScaleCommand(const ScaleCommand&) = delete;
        ScaleCommand(ScaleCommand&&) = delete;
        ScaleCommand& operator=(const ScaleCommand&) = delete;
        ScaleCommand& operator=(ScaleCommand&&) = delete;
    };
}
