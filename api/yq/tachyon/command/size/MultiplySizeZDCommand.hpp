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
    class MultiplySizeᶻDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySizeᶻDCommand, SizeCommand)
    public:
        MultiplySizeᶻDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySizeᶻDCommand(const MultiplySizeᶻDCommand&, const Header&);
        MultiplySizeᶻDCommand(const Header&);
        ~MultiplySizeᶻDCommand();

    private:
        double  m_δz = 0.0;
        
        MultiplySizeᶻDCommand(const MultiplySizeᶻDCommand&) = delete;
        MultiplySizeᶻDCommand(MultiplySizeᶻDCommand&&) = delete;
        MultiplySizeᶻDCommand& operator=(const MultiplySizeᶻDCommand&) = delete;
        MultiplySizeᶻDCommand& operator=(MultiplySizeᶻDCommand&&) = delete;
    };
}
