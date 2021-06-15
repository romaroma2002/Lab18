object Form1: TForm1
  Left = 224
  Top = 61
  Width = 928
  Height = 483
  Caption = 'CDB Editor'
  Color = clBtnFace
  Constraints.MinHeight = 300
  Constraints.MinWidth = 450
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object StringGrid1: TStringGrid
    Left = 8
    Top = 8
    Width = 897
    Height = 409
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing, goEditing]
    ParentFont = False
    TabOrder = 0
    Visible = False
    OnSelectCell = StringGrid1SelectCell
    OnSetEditText = StringGrid1SetEditText
  end
  object MainMenu1: TMainMenu
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1057#1090#1074#1086#1088#1080#1090#1080
        OnClick = Create
      end
      object N3: TMenuItem
        Caption = #1042#1110#1076#1082#1088#1080#1090#1080
        OnClick = Open
      end
      object N4: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080
        OnClick = Save
      end
      object N5: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080' '#1103#1082
        OnClick = SaveAs
      end
      object N6: TMenuItem
        Caption = #1047#1072#1082#1088#1080#1090#1080
        OnClick = Close
      end
    end
    object N7: TMenuItem
      Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1090#1080
      object N8: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1080#1090#1080' '#1088#1103#1076#1086#1082
        OnClick = AddRow
      end
      object N9: TMenuItem
        Caption = #1042#1080#1076#1072#1083#1080#1090#1080' '#1088#1103#1076#1086#1082
        OnClick = DelRow
      end
      object N10: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1080#1090#1080' '#1089#1090#1086#1074#1087#1077#1094#1100
        OnClick = AddCol
      end
      object N11: TMenuItem
        Caption = #1042#1080#1076#1072#1083#1080#1090#1080' '#1089#1090#1086#1074#1087#1077#1094#1100
        OnClick = DelCol
      end
    end
    object N12: TMenuItem
      Caption = #1055#1086#1096#1091#1082
      OnClick = Search
    end
    object N13: TMenuItem
      Caption = #1060#1110#1083#1100#1090#1088
      OnClick = Filter
    end
    object N14: TMenuItem
      Caption = #1057#1086#1088#1090#1091#1074#1072#1085#1085#1103
      OnClick = Sort
    end
    object N15: TMenuItem
      Caption = #1045#1082#1089#1087#1086#1088#1090
      object Excel1: TMenuItem
        Caption = #1045#1082#1089#1087#1086#1088#1090' '#1074' Excel'
        OnClick = Excel1Click
      end
      object csv1: TMenuItem
        Caption = #1045#1082#1089#1087#1086#1088#1090' '#1074' CSV'
        OnClick = csv1Click
      end
    end
    object N16: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      OnClick = N16Click
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = #1060#1072#1081#1083' CDB (*.cdb)|*.cdb'
    Left = 24
  end
  object SaveDialog1: TSaveDialog
    Filter = #1060#1072#1081#1083' CDB(*.cdb)|*.cdb'
    Left = 48
  end
  object SaveDialog2: TSaveDialog
    Filter = 'CSV (*.csv)|*.csv'
    Left = 72
  end
end
