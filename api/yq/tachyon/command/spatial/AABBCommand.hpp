////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SpatialCommand.hpp>

namespace yq::tachyon {
    class AABBCommand : public SpatialCommand {
        YQ_OBJECT_DECLARE(AABBCommand, SpatialCommand)
    public:
        AABBCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        AABBCommand(const AABBCommand&, const Header&);
        virtual ~AABBCommand();
        
    private:

        AABBCommand(const AABBCommand&) = delete;
        AABBCommand(AABBCommand&&) = delete;
        AABBCommand& operator=(const AABBCommand&) = delete;
        AABBCommand& operator=(AABBCommand&&) = delete;
    };
}
