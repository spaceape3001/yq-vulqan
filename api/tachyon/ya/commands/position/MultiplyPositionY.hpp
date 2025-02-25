////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class MultiplyPositionʸ : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPositionʸ, PositionCommand)
    public:
        MultiplyPositionʸ(const Header&, double);
        
        static void init_info();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPositionʸ(const MultiplyPositionʸ&, const Header&);
        MultiplyPositionʸ(const Header&);
        ~MultiplyPositionʸ();

    private:
        double  m_δy = 0.0;
        
        MultiplyPositionʸ(const MultiplyPositionʸ&) = delete;
        MultiplyPositionʸ(MultiplyPositionʸ&&) = delete;
        MultiplyPositionʸ& operator=(const MultiplyPositionʸ&) = delete;
        MultiplyPositionʸ& operator=(MultiplyPositionʸ&&) = delete;
    };
}
