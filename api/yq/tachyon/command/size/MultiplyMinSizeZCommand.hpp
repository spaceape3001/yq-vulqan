////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class MultiplyMinSizeᶻCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSizeᶻCommand, SizeCommand)
    public:
        MultiplyMinSizeᶻCommand(const Header&, double);
        
        static void init_meta();
        
        double  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSizeᶻCommand(const MultiplyMinSizeᶻCommand&, const Header&);
        MultiplyMinSizeᶻCommand(const Header&);
        ~MultiplyMinSizeᶻCommand();

    private:
        double  m_δz = 0.0;
        
        MultiplyMinSizeᶻCommand(const MultiplyMinSizeᶻCommand&) = delete;
        MultiplyMinSizeᶻCommand(MultiplyMinSizeᶻCommand&&) = delete;
        MultiplyMinSizeᶻCommand& operator=(const MultiplyMinSizeᶻCommand&) = delete;
        MultiplyMinSizeᶻCommand& operator=(MultiplyMinSizeᶻCommand&&) = delete;
    };
}
