#!/usr/bin/env python

import json
payload = {}
payload["options"] = {}
payload["options"]["simulation_start_time"] = 0
payload["options"]["simulation_end_time"] = 100
payload["options"]["simulation_tick"] = 1

print json.dumps(payload, indent=4)
