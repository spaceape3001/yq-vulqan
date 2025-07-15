#! Assets (Tachyon)

NOTE: Read the documentation in the toolbox for understanding of the mechanics.

## Paths

Pathing can be configured with

    #include <tachyon/app/Application.hpp>
    yq::tachyon::configure_standard_asset_path();
    
And it's auto-configured by application startup for vulkan applications (from the `vulqan.cfg` file)
