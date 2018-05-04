#!/bin/bash

# e.sh (2pts) - Implements lspci.
# Read the file /proc/bus/pci/devices line by line using the second (pciid)
# and 18th (driver) fields and look-up the PCI manufacturer in the
# /usr/share/pci.ids device database file.
# Example input/output:
# ./e.sh
#                 8086.0c04 Intel Corporation Xeon E3-1200 v3/4th Gen Core Processor DRAM Controller
#            i915 8086.0416 Intel Corporation 4th Gen Core Processor Integrated Graphics Controller
#   snd_hda_intel 8086.0c0c Intel Corporation Xeon E3-1200 v3/4th Gen Core Processor HD Audio Controller
#        xhci_hcd 8086.8c31 Intel Corporation 8 Series/C220 Series Chipset Family USB xHCI
# ...

# Use a while loop and read to read the fields out of the /proc/bus/pci/devices file:
# Save the pciid (field 2) and driver fields (field 18)

  
  # Use the first 4 characters of pciid for the vendor ID
  
  # Use the last 4 characters of pciid for the card ID
  
  # The vendor is identified in /usr/share/pci.ids by the vendor ID at the
  # very beginning of the line.
  
  # The card description is the card ID prefixed with a tab that follows the
  # line with the vendor ID. Different cards may have the same card ID, but
  # different vendor IDs, so be careful you get the right description.
  
  
  
  
  
  
  
  # Use printf to print the driver (right aligned 15 characters, then the
  # vendor and card id's separated by a dot, then finally the vendor description
  # followed by the card description.
  

