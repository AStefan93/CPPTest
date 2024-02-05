const TCPConnection = createMachine({
  /** @xstate-layout N4IgpgJg5mDOIC5QBUDCAFVB7AdjsAxgC4CWuAdAQDZawk5QDEEuY59AblgNZvW30oAbQAMAXUSgADgNK5JIAB6IAjCoAsAZnIBOEQFYVm9QCZ96kSZX6ANCACeiABwnympx5079T-SZNO6gBsAL4hdmiYuPjEZDiUNLCQjADy6ACiAHKiEkggMnRyOArKCE5BOuQmmiouAOwV1kEqdo4IJiIq5FrWRpo1Fvr6YREY2HiERewQVGCMAMrIAIIASsg5CgUkRSWIOkZVhnXGdeo6xt6tiCbN5H5OKiIiQSZnQ+ojIJHjMVMkM3NUAAZFLzdIbPJbHZ5UpqLS6AxGUzmSzWK7tW73R7PV7ecyfb7RSZxcgAJwArnhBMxWOwcFxeGTKThBBDpLI4rsyhUqjV6o19M10TUui9gk46vtfAZjASxkTYhQKVSGIwwKTSVhSeQpFQAIZEABmWoAtkyVcJxJsOfIYc4edVaiYGvtBS0HIh3NofB1Tio6tUApo5VEJor4sqWar0EsAKpgtn5G3FO0IfSWciSuq1TTVCovETqdH+pzkWrZnS+APWQYhn7EpXM6nA0Hgq2Q5Nc8qVR3811Cj0ILQichBILHTpj8WvOsKqZSPXkuiqlj4OkMtgLpes9vswqc1P+fR3B43TSSvR+IuD0x1KqIh7BSwmc6zsPzxfLpjqzXa3UG41STNLcv0TKED1AUojxPFQzwvAxXmFJ4qnUNRqxUbwbh0N9fhJEDkkWVZ1l3JN91tSDEHTVwzGOHQXneJxc3RVCe0YupfHKfQ6kLHCG3ifCIEYFsExI8DyKUSiMxozQ6LMcxGJMdEhi6Kwhm8EV1C44NPhwLAIDgBRCXfCDSO2EzSgAWjqY86MrAMRE0EQ6gaZ50Qs49Ok02DHheCpuNCcIvnlYyKH4L9rTIlMKIQIxnlHXMLHKGp+hcYVNGPdRNO4jCAnMHQPkCozcNCxJIAiszxNKY51F0SsJUciVNJ0Op0XKTMxwDSV+i6xjePDaZZnK6FoseV5R2rSUgjOHQOk0dEbi6FwZvUbMnC8dQHmGQrguKiMmwYIbzMQZoavMLRcxUCpzwaea-DLQsLwlLiVuavqP23A6O0irkLOdXQKglWanJcoJixeMsmq8fwZPTSs3rwz8yq+iqookhAvXISxMtQoJDHcDDbBvG5MaeKbT2CV4VDCMIgA */
  id : "TCPConnection",
  initial : "closed",
  states : {
    closing : {
      entry : "startClosingTimer",
      invoke : {src : "timer", id : "closing", onDone : "closed"},
      exit : "stopClosingTimer",
    },
    closed : {on : {OPEN : "idle"}},
    idle : {on : {START : "running", CLOSE : "closing"}},
    running : {
      on : {PAUSE : "pausing", CLOSE : "closing"},
      entry : "startRunningTimer",
      invoke :
          {src : "timer", id : "running", onDone : "idle", onError : "closing"},
      exit : "stopRunningTimer",
    },
    pausing : {
      entry : "startPausingTimer",
      invoke : {
        src : "timer",
        id : "pausing",
        onDone : "paused",
        onError : "running"
      },
      exit : "stopPausingTimer",
    },
    paused : {on : {START : "running", CLOSE : "closing"}},
  },
})