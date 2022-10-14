




def main():
    parser = ArgumentParser()
    parser.add_argument('-path', type=str, required=True, help=f'The name of the {Workbook.__name__} or a path to '
                                                               f'the directory containing {Workbook.__name__}s.')
    input_source = _get_input_source(parser.parse_args().path)
    if input_source:
        _workbooks2csv(input_source)


if __name__ == '__main__':
    main()
