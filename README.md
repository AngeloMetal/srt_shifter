# srt_shifter
Resync your subtitles

# Compiling and running
Compile with ``make`` and run with ``./srt <file.srt> <seconds> > <new_file.srt>``.

# Example
Assume we have ``sub_test.srt``:
```
1
00:00:00,000 --> 00:00:05,000
Hello, World!

2
00:00:05,500 --> 00:00:10,000
This is a test subtitle file.

3
00:00:10,500 --> 00:00:15,000
It contains three subtitle entries.
```

Once ``./srt sub_test.srt 5 > new_sub_test.srt`` executed, ``new_sub_test.srt`` will be:
```
1
00:00:05,000 --> 00:00:10,000
Hello, World!

2
00:00:10,500 --> 00:00:15,000
This is a test subtitle file.

3
00:00:15,500 --> 00:00:20,000
It contains three subtitle entries.
```

## TODO:
- Float instead of integers in seconds.