/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2020, The LineageOS Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>

#include "init_msm8974.h"

using android::base::GetProperty;

void vendor_load_properties()
{
    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("G900AZ") == 0) {
        /* klteaio - Cricket MVNO */
        property_override("ro.build.description", "kltetu-user 5.0 LRX21T G900AZTUS3BQD1 release-keys");
        set_ro_product_prop("device", "klteaio");
        set_ro_product_prop("build.fingerprint", "samsung/kltetu/klteaio:5.0/LRX21T/G900AZTUS3BQD1:user/release-keys");
        set_ro_product_prop("model", "SM-G900AZ");
        set_ro_product_prop("name", "klteaio");
        gsm_properties("9", "gsm");
    } else if (bootloader.find("S902L") == 0) {
        /* kltetfnvzw - SM-S902L - TracFone Verizon MVNO */
        property_override("ro.build.description", "kltetfnvzw-user 4.4.2 KOT49H S902LUDUAOD3 release-keys");
        property_override("ro.telephony.get_imsi_from_sim", "true");
        set_ro_product_prop("device", "kltetfnvzw");
        set_ro_product_prop("build.fingerprint", "samsung/kltetfnvzw/kltetfnvzw:4.4.2/KOT49H/S902LUDUAOD3:user/release-keys");
        set_ro_product_prop("model", "SM-S902L");
        set_ro_product_prop("name", "kltetfnvzw");
        cdma_properties("TracFone", "310000", "0", "10", "vzw");
    } else {
        gsm_properties("9", "gsm");
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}
