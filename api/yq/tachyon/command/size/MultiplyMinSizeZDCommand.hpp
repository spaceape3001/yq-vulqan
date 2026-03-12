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
    class MultiplyMinSizeᶻDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSizeᶻDCommand, SizeCommand)
    public:
        MultiplyMinSizeᶻDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSizeᶻDCommand(const MultiplyMinSizeᶻDCommand&, const Header&);
        MultiplyMinSizeᶻDCommand(const Header&);
        ~MultiplyMinSizeᶻDCommand();

    private:
        double  m_δz = 0.0;
        
        MultiplyMinSizeᶻDCommand(const MultiplyMinSizeᶻDCommand&) = delete;
        MultiplyMinSizeᶻDCommand(MultiplyMinSizeᶻDCommand&&) = delete;
        MultiplyMinSizeᶻDCommand& operator=(const MultiplyMinSizeᶻDCommand&) = delete;
        MultiplyMinSizeᶻDCommand& operator=(MultiplyMinSizeᶻDCommand&&) = delete;
    };
}
