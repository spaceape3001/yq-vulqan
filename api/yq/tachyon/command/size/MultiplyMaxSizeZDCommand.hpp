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
    class MultiplyMaxSizeᶻDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSizeᶻDCommand, SizeCommand)
    public:
        MultiplyMaxSizeᶻDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSizeᶻDCommand(const MultiplyMaxSizeᶻDCommand&, const Header&);
        MultiplyMaxSizeᶻDCommand(const Header&);
        ~MultiplyMaxSizeᶻDCommand();

    private:
        double  m_δz = 0.0;
        
        MultiplyMaxSizeᶻDCommand(const MultiplyMaxSizeᶻDCommand&) = delete;
        MultiplyMaxSizeᶻDCommand(MultiplyMaxSizeᶻDCommand&&) = delete;
        MultiplyMaxSizeᶻDCommand& operator=(const MultiplyMaxSizeᶻDCommand&) = delete;
        MultiplyMaxSizeᶻDCommand& operator=(MultiplyMaxSizeᶻDCommand&&) = delete;
    };
}
