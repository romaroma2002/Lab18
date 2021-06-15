object Form7: TForm7
  Left = 651
  Top = 301
  Width = 300
  Height = 250
  Caption = #1047#1085#1072#1081#1090#1080
  Color = clBtnFace
  Constraints.MaxHeight = 250
  Constraints.MaxWidth = 300
  Constraints.MinHeight = 250
  Constraints.MinWidth = 300
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 90
    Top = 28
    Width = 90
    Height = 13
    Caption = #1058#1077#1082#1089#1090' '#1076#1083#1103' '#1087#1086#1096#1091#1082#1091
  end
  object Label2: TLabel
    Left = 98
    Top = 92
    Width = 74
    Height = 13
    Caption = #1056#1077#1078#1080#1084' '#1087#1086#1096#1091#1082#1091
  end
  object Edit1: TEdit
    Left = 84
    Top = 48
    Width = 105
    Height = 21
    TabOrder = 0
    OnChange = Edit1Change
  end
  object Button1: TButton
    Left = 72
    Top = 144
    Width = 128
    Height = 25
    Caption = #1047#1085#1072#1081#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object ComboBox1: TComboBox
    Left = 84
    Top = 108
    Width = 105
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 2
    Text = #1044#1086#1088#1110#1074#1085#1102#1108
    OnChange = ComboBox1Change
    Items.Strings = (
      #1044#1086#1088#1110#1074#1085#1102#1108
      #1052#1110#1089#1090#1080#1090#1100
      #1055#1086#1095#1080#1085#1072#1108#1090#1100#1089#1103' '#1085#1072
      #1047#1072#1082#1110#1085#1095#1091#1108#1090#1100#1089#1103' '#1085#1072)
  end
end
