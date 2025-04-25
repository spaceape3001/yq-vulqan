////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class MultiplyPositionᶻ : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPositionᶻ, PositionCommand)
    public:
        MultiplyPositionᶻ(const Header&, double);
        
        static void init_info();
        
        double  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPositionᶻ(const MultiplyPositionᶻ&, const Header&);
        MultiplyPositionᶻ(const Header&);
        ~MultiplyPositionᶻ();

    private:
        double  m_δz = 0.0;
        
        MultiplyPositionᶻ(const MultiplyPositionᶻ&) = delete;
        MultiplyPositionᶻ(MultiplyPositionᶻ&&) = delete;
        MultiplyPositionᶻ& operator=(const MultiplyPositionᶻ&) = delete;
        MultiplyPositionᶻ& operator=(MultiplyPositionᶻ&&) = delete;
    };
}
