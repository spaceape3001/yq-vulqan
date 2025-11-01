////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class MultiplyPositionʸCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPositionʸCommand, PositionCommand)
    public:
        MultiplyPositionʸCommand(const Header&, double);
        
        static void init_meta();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPositionʸCommand(const MultiplyPositionʸCommand&, const Header&);
        MultiplyPositionʸCommand(const Header&);
        ~MultiplyPositionʸCommand();

    private:
        double  m_δy = 0.0;
        
        MultiplyPositionʸCommand(const MultiplyPositionʸCommand&) = delete;
        MultiplyPositionʸCommand(MultiplyPositionʸCommand&&) = delete;
        MultiplyPositionʸCommand& operator=(const MultiplyPositionʸCommand&) = delete;
        MultiplyPositionʸCommand& operator=(MultiplyPositionʸCommand&&) = delete;
    };
}
